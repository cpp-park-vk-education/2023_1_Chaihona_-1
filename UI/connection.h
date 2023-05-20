// #ifndef CONNECTION_H
// #define CONNECTION_H

// #include "QMessageBox"
// #include "QtSql"
// #include "QSqlDatabase"

// inline bool createConnection(){
//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setDatabaseName("postgres1");
//    db.setUserName("postgres2");
//    db.setPassword("03795");

//    if (!db.open()){
//        QMessageBox::warning(0, "DB Error", db.lastError().text());
//        return false;
//    }
//    else{
//        QMessageBox::information(0, "Success", "Connected!");
//        return true;
//    }
// }

// inline bool createTable(){
//     QSqlQuery query;
//     //query.exec("1");

//     query.exec("CREATE TABLE hobby ("
//                "id INTEGER PRIMARY KEY, "
//                "name VARCHAR(50) NOT NULL, "
//                "surname VARCHAR(50) NOT NULL, "
//                "date_of_birth DATE)");
//     return(1);
// }

// #endif // CONNECTION_H
