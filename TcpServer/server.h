#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    int count();
    void close();

    QString message() const;
    void setMessage(const QString &message);
    
signals:
    void changed();
    
public slots:
    void disConnected();
    void readyRead();

private:
    QString m_message;
    QList<QTcpSocket*> m_list;

protected:
    void incomingConnection(qintptr handle) override;


    
};
#endif // SERVER_H
