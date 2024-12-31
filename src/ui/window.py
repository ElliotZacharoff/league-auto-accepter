import ctypes

from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

backend = ctypes.CDLL("../uiserver.so")

backend.isValidChamp.argtypes = [ctypes.c_char_p] # parameter type(s)
backend.isValidChamp.restype = int # restype = return type

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("League auto-accepter")
        self.setGeometry(100, 100, 400, 300)

        cW = QWidget()
        self.setCentralWidget(cW)

        main_layout = QVBoxLayout(cW)

        gB = QGroupBox("Enter a champion")
        gB_layout = QVBoxLayout()
        gB.setLayout(gB_layout)
        main_layout.addWidget(gB)

        self.tb = QLineEdit(self)
        self.tb.setPlaceholderText("Champion...")
        gB_layout.addWidget(self.tb)

        self.submits = []
        self.submit_button = QPushButton("Send to C Backend", self)
        self.submit_button.clicked.connect(self.on_submit)
        gB_layout.addWidget(self.submit_button)

        self.fbStr = QLabel("", self)
        gB_layout.addWidget(self.fbStr)

    @pyqtSlot()
    def on_submit(self):
        userInput = self.tb.text()

        if (userInput == ""):
            return

        subn = len(self.submits)+1
        self.submits.append(userInput)
        is_valid = backend.isValidChamp(userInput.encode('utf-8'))
        if subn >= 5:
            self.fbStr.setText("Maximum submissions reached! (5/5)")
            self.submit_button.setEnabled(False)
            return
        if is_valid == 1:
            self.fbStr.setText(f"Added {userInput} ({subn}/5)")
            self.tb.setText("")
        else:
            self.fbStr.setText(f"{userInput} is not a valid champion")
            self.submits.pop()