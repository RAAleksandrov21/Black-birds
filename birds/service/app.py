from flask import Flask

app = Flask(__name__)

@app.route('/', methods=["GET"])

def get_articles():
    return "Hello"

if __name__ == "__main__":
    app.run(debug=True)
