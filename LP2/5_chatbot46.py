import webbrowser
from datetime import date,datetime

responses = {
    "Hii": "Hii bro:",
    "hello": "Hello",
    "date" : str(datetime.now()),
    "youtube" : "Sure",
    "default" : "?"
}

def chat():
    while(True):
        ui = input("YOU:").lower()
        print(ui)
        res = responses.get(ui,responses["default"])
        print("BOT:",res)
        if ui=="youtube":
            webbrowser.open("youtube.com")
        if ui=="bye":
            print("BYE bRo")
            break

chat()
