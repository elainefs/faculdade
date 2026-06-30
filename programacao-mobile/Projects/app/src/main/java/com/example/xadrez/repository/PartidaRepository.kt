package com.example.xadrez.repository

import android.content.ContentValues
import android.content.Context
import com.example.xadrez.database.DatabaseHelper

class PartidaRepository(private val context: Context) {

    fun inserirPartida(jogador1: String, jogador2: String, vencedor: String?) {
        val dbHelper = DatabaseHelper(context)
        val db = dbHelper.writableDatabase

        val values = ContentValues().apply {
            put("jogador1", jogador1)
            put("jogador2", jogador2)
            put("vencedor", vencedor)
            val agora = System.currentTimeMillis().toString()
            put("criado_em", agora)
            put("atualizado_em", agora)
        }

        db.insert("Partidas", null, values)
        db.close()
    }

    fun consultarClassificacao(): List<Triple<Int, String, Int>> {
        val dbHelper = DatabaseHelper(context)
        val db = dbHelper.readableDatabase

        val cursor = db.rawQuery(
            """
            SELECT vencedor, COUNT(*) as vitorias
            FROM Partidas
            WHERE vencedor IS NOT NULL
            GROUP BY vencedor
            ORDER BY vitorias DESC
            """, null
        )

        val lista = mutableListOf<Triple<Int, String, Int>>()
        var posicao = 1
        while (cursor.moveToNext()) {
            val nome = cursor.getString(0)
            val vitorias = cursor.getInt(1)
            lista.add(Triple(posicao, nome, vitorias))
            posicao++
        }

        cursor.close()
        db.close()
        return lista
    }
}
