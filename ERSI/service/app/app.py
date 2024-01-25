from flask import Flask, request, jsonify
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user
from flask_bcrypt import Bcrypt
from flask_cors import CORS

app = Flask(__name__)
CORS(app, resources={r"/*": {"origins": "192.168.1.13:29006"}})

app.config['SQLALCHEMY_DATABASE_URI'] = "postgresql://postgres:1234@localhost/ersi"
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
    
    with app.app_context():
        db.session.add(new_user)
        db.session.commit()

    return jsonify({"message": "Registration successful" })

@app.route('/login', methods=['GET'])
def login():
    email = request.args.get('email')
    password = request.args.get('password')

    user = User.query.filter_by(email=email).first()

    if user and bcrypt.check_password_hash(user.password, password):
        login_user(user)
        return jsonify({"message": "Login successful"})
    else:
        return jsonify({"message": "Invalid email or password"}), 401

@app.route("/create_post", methods=["POST"])
def create_post():
    user_id = request.get_json()["user_id"]

    new_testament = Testament(
        user_id=user_id,
        fulname=request.get_json()["fulname"],
        typetestament=request.get_json()["typetestament"],
        body=request.get_json()["body"]
    )

    with app.app_context():
        db.session.add(new_testament)
        db.session.commit()

    return jsonify({"message": "Testament successful!"})

if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    app.run(host="0.0.0.0", port=5000, debug=True)
