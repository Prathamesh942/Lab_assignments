from nltk.chat.util import Chat, reflections

pairs = [
	[
		r"what is your name ?",
		["My name is --"]
	],
]

def mybot():
	print("Hii")
	chat = Chat(pairs, reflections)
	chat.converse()

mybot()
