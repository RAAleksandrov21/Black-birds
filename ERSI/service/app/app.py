from flask import Flask, request, jsonify
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, current_user, login_required
from flask_bcrypt import Bcrypt
from flask_cors import CORS

app = Flask(__name__)
CORS(app, resources={r"/*": {"origins": "*"}})

app.config['SQLALCHEMY_DATABASE_URI'] = "postgresql://postgres:1234@localhost/ersidb"
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SECRET_KEY'] = 'your_secret_key'

db = SQLAlchemy(app)

bcrypt = Bcrypt(app)

login_manager = LoginManager(app)
login_manager.login_view = 'login'

class User(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    fname = db.Column(db.String(80), nullable=False)
    lname = db.Column(db.String(80), nullable=False)
    email = db.Column(db.String(120), unique=True, nullable=False)
    password = db.Column(db.String(60), nullable=False)


class Testament(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey("user.id"), nullable=False)
    fullname = db.Column(db.String(200), nullable=False)
    typetestament = db.Column(db.String(200), nullable=False)
    body = db.Column(db.Text, nullable=False)
    
    def serialize(self):
        return {
            'id': self.id,
            'user_id': self.user_id,
            'fullname': self.fullname,
            'typetestament': self.typetestament,
            'body': self.body
        }

@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))

# Routes
@app.route('/register', methods=['POST'])
def register():
    data = request.json
    
    fname = data.get('fname')
    lname = data.get('lname')
    email = data.get('email')
    password = data.get('password')

    hashed_password = bcrypt.generate_password_hash(password).decode('utf-8')

    new_user = User(fname=fname, lname=lname, email=email, password=hashed_password)
    
    
    db.session.add(new_user)
    db.session.commit()

    return jsonify({"message": "Registration successful","user_id": new_user.id }),200

@app.route('/login', methods=['GET'])
def login():
    email = request.args.get('email')
    password = request.args.get('password')

    user = User.query.filter_by(email=email).first()

    if user and bcrypt.check_password_hash(user.password, password):
        login_user(user)
        return jsonify({"message": "Login successful", "user_id": user.id}),200
    else:
        return jsonify({"message": "Invalid email or password"}), 401

@app.route("/create_post", methods=["POST"])
def create_post():
    user_id = request.get_json().get("user_id")

    # Check if user_id is present
    if user_id is None:
        print("user_id is missing")
        return jsonify({"message": "user_id is missing"}), 400

    print("Received payload:", request.get_json())  # Add this line

    # Create a new testament with the provided user_id
    new_testament = Testament(
        user_id=user_id,
        fullname=request.get_json().get("fullname"),
        typetestament=request.get_json().get("typetestament"),
        body=request.get_json().get("body")
    )

    # Add the new testament to the database
    with app.app_context():
        db.session.add(new_testament)
        db.session.commit()

    return jsonify({"message": "Testament successful!"})

@app.route('/get_testaments', methods=['GET'])
@login_required
def get_testaments():
    current_user_id = current_user.id
    testaments = Testament.query.filter_by(user_id=current_user_id).all()
    return jsonify([testament.serialize() for testament in testaments])

@app.route('/user/<user_id>', methods=['GET'])
def get_user(user_id):
    user = User.query.filter_by(id=user_id).first()
    if user:
        return jsonify({
            'fname': user.fname,
            'lname': user.lname,
            'email': user.email
        })
    else:
        return jsonify({'error': 'User not found'}), 404

if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    app.run(host="0.0.0.0", port=5000, debug=True)
