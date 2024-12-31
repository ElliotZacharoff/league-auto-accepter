
from window import MainWindow
from PyQt5 import QtWidgets
import sys

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec_())