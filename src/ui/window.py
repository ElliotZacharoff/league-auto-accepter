import ctypes

from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

backend = ctypes.CDLL("../uiserver.so")

backend.isValidChamp.argtypes = [ctypes.c_char_p] # parameter type(s)
backend.isValidChamp.restype = None # restype = return type

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("League auto-accepter")
        self.setGeometry(100, 100, 400, 300)

        cW = QWidget()
        self.setCentralWidget(cW)

        gB = QGroupBox("Button Groupbox")
        gB_layout = QVBoxLayout(cW)
        gB.setLayout(gB_layout)

        self.tb = QLineEdit(self)
        self.tb.setPlaceholderText("Champion...")
        gB_layout.addWidget(self.tb)

        # Submit button
        self.submits = []
        self.submit_button = QPushButton("Send to C Backend", self)
        self.submit_button.clicked.connect(self.on_submit)
        gB_layout.addWidget(self.submit_button)

        # Feedback label
        self.fbStr = QLabel("", self)
        gB_layout.addWidget(self.fbStr)

    @pyqtSlot()
    def on_submit(self):
        subn = len(self.submits)
        if subn > 5:
            pass
        userInput = self.tb.text()
        self.submits.append(userInput)
        backend.isValidChamp(userInput.encode('utf-8'))

        self.fbStr.setText(f"Added {userInput.encode('utf-8')} ({subn}/5)")
