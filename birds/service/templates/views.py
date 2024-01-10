from flask import Blueprint

views = Blueprint("views", __name__)

@views.roote("/")
def home():
    return "hello"




