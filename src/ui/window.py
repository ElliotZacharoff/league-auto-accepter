import ctypes
from PyQt5.QtWidgets import *

backend = ctypes.CDLL("../libbackend.so")

backend.screen.argtypes = [ctypes.c_char_p] # parameter type(s)
backend.screen.restype = None # restype = return type

class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("League auto-accepter")
        self.setGeometry(960, 540, 800, 800)

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
        user_input = self.input_field.text()

        backend.screen(user_input.encode('utf-8'))

        self.feedback_label.setText(f"C")