package com.example.xadrez.database

import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class DatabaseHelper(context: Context) : SQLiteOpenHelper(
    context,
    DATABASE_NAME,
    null,
    DATABASE_VERSION
) {
    override fun onCreate(db: SQLiteDatabase) {
        db.execSQL(
            """
            CREATE TABLE User (
                nome TEXT NOT NULL,
                email TEXT PRIMARY KEY,
                senha TEXT NOT NULL,
                curso TEXT,
                turma TEXT,
                criado_em TEXT,
                atualizado_em TEXT
            )
            """
        )

        db.execSQL(
            """
            CREATE TABLE Partidas (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                jogador1 TEXT NOT NULL,
                jogador2 TEXT NOT NULL,
                vencedor TEXT,
                criado_em TEXT,
                atualizado_em TEXT,
                FOREIGN KEY(jogador1) REFERENCES User(email),
                FOREIGN KEY(jogador2) REFERENCES User(email),
                FOREIGN KEY(vencedor) REFERENCES User(email)
            )
            """
        )
    }

    override fun onUpgrade(db: SQLiteDatabase, oldVersion: Int, newVersion: Int) {
        db.execSQL("DROP TABLE IF EXISTS User")
        db.execSQL("DROP TABLE IF EXISTS Partidas")
        onCreate(db)
    }

    companion object {
        private const val DATABASE_NAME = "xadrez.db"
        private const val DATABASE_VERSION = 1
    }
}
