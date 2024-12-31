import ctypes
from PyQt5.QtWidgets import *

backend = ctypes.CDLL("../libbackend.so")

backend.screen.argtypes = [ctypes.c_char_p] # parameter type(s)
backend.screen.restype = None # restype = return type

matches = []
filePath = "../champions.txt"

def compare_to_file(string: str):
    with open(filePath, "r") as f:
        lines = f.readlines()
        for line in lines:
            if string == line:
                matches.append(string)

class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("League auto-accepter")
        self.setGeometry(200, 540, 200, 200)

        widget = QWidget()
        self.setCentralWidget(widget)

        layout = QVBoxLayout()
        widget.setLayout(layout)

        self.input_field = QLineEdit(self)
        self.input_field.setPlaceholderText("Enter something...")
        layout.addWidget(self.input_field)

        self.submit_button = QPushButton("Send to C Backend", self)
        self.submit_button.clicked.connect(self.on_submit)
        layout.addWidget(self.submit_button)

        self.feedback_label = QLabel("", self)
        layout.addWidget(self.feedback_label)


    def on_submit(self):
        userInput = self.input_field.text()

        compare_to_file(userInput)
        backend.screen(userInput.encode('utf-8'))

        self.feedback_label.setText(f"HELLO")

    def handle_input(self):
        pass