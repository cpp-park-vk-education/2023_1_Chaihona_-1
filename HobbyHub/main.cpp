#include <QApplication>
#include <QTest>
#include <iostream>
#include <cstdlib>
#include <QDialog>

#include <cstdio>
#include "tests.h"
#include "greetingpage.h"
#include "QTcpSocket"


/*class Dialog : public QDialog
{
private slots:
//определим слоты для обработки сигналов сокета
    void onSokConnected();
    void onSokDisconnected();
//сигнал readyRead вызывается, когда сокет получает пакет (который может быть лишь частью отправленых данных) байтов
    void onSokReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);
private:
    QTcpSocket *_sok; //сокет
    quint16 _blockSize;//текущий размер блока данных
    QString _name;//имя клиента
};


Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog)
{
//создаем сокет
    _sok = new QTcpSocket(this);
//подключаем сигналы
    connect(_sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(_sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(_sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(_sok, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

//по нажатию кнопки подключаемся к северу, отметим, что connectToHost() возвращает тип void, потому, что это асинхронный вызов и в случае ошибки будет вызван слот onSokDisplayError
void Dialog::on_pbConnect_clicked()
{
    _sok->connectToHost(ui->leHost->text(), ui->sbPort->value());
}

void Dialog::onSokConnected()
{
//после подключения следует отправить запрос на авторизацию
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
//резервируем 2 байта для размера блока. Класс MyClient используется в реализации сервера, но тут используем статические члены этого класса - константы команд
//третий байт - команда
    out << (quint16)0 << (quint8)MyClient::comAutchReq << ui->leName->text();
    _name = ui->leName->text();
//возваращаемся в начало
    out.device()->seek(0);
//вписываем размер блока на зарезервированное место
    out << (quint16)(block.size() - sizeof(quint16));
    _sok->write(block);
}

void Dialog::onSokReadyRead()
{
//тут обрабатываются данные от сервера
    QDataStream in(_sok);
//если считываем новый блок первые 2 байта это его размер
    if (_blockSize == 0) {
//если пришло меньше 2 байт ждем пока будет 2 байта
        if (_sok->bytesAvailable() < (int)sizeof(quint16))
            return;
//считываем размер (2 байта)
        in >> _blockSize;
    }
//ждем пока блок прийдет полностью
    if (_sok->bytesAvailable() < _blockSize)
        return;
    else
//можно принимать новый блок
        _blockSize = 0;
//3 байт - команда серверу
    quint8 command;
    in >> command;

    switch (command)
    {
//сервер отправит список пользователей, если авторизация пройдена, в таком случае третий байт равен константе MyClient::comUsersOnline
        case MyClient::comUsersOnline:
        {
            QString users;
            in >> users;
            if (users == "")
                return;
//сервер передает имена через запятую, как строку (хотя можно писать в поток и объект QStringList)
            QStringList l =  users.split(",");
//обновляем гуи
            ui->lwUsers->addItems(l);
        }
        break;
//общее сообщение от сервера
        case MyClient::comPublicServerMessage:
        {
//считываем и добавляем в лог
            QString message;
            in >> message;
            AddToLog("[PublicServerMessage]: "+message, Qt::red);
        }
        ...
    }
}
*/


int main(int argc, char *argv[])
{


//       freopen("testing.log", "w", stdout); // тесты к окну greetingpage
//       QApplication a(argc, argv);
//       QTest::qExec(new Test_QLineEdit, argc, argv);
//       QTest::qExec(new Test_QPushButton, argc, argv);
//       QTest::qExec(new TestMainWindow, argc, argv);
//       return 0;

    QApplication a(argc, argv); //запуск приложения
    GreetingPage w;
    w.show();
    return a.exec();

}

