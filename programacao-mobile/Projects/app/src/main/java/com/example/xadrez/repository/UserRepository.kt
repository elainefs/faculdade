package com.example.xadrez.repository

import android.content.ContentValues
import android.content.Context
import com.example.xadrez.database.DatabaseHelper
import com.example.xadrez.model.Usuario
import java.security.MessageDigest

class UserRepository(private val context: Context) {
    fun hashSenha(senha: String): String {
        val md = MessageDigest.getInstance("SHA-256")
        val bytes = md.digest(senha.toByteArray())
        return bytes.joinToString("") { "%02x".format(it) }
    }

    fun emailExiste(email: String): Boolean {
        val dbHelper = DatabaseHelper(context)
        val db = dbHelper.readableDatabase

        val cursor = db.rawQuery("SELECT email FROM User WHERE email = ?", arrayOf(email))
        val existe = cursor.count > 0

        cursor.close()
        db.close()
        return existe
    }

    fun inserirUsuario(nome: String, email: String, senhaPura: String, curso: String, turma: String): Boolean {
        if (nome.isBlank()) {
            throw IllegalArgumentException("O campo nome não pode ser vazio.")
        }

        if (email.isBlank()) {
            throw IllegalArgumentException("A campo e-mail não pode ser vazio.")
        }

        if (senhaPura.isBlank()) {
            throw IllegalArgumentException("A campo senha não pode ser vazio.")
        }

        if (senhaPura.length < 8) {
            throw IllegalArgumentException("A senha deve ter pelo menos 8 caracteres.")
        }

        if (emailExiste(email)) {
            throw IllegalArgumentException("Este e-mail já está cadastrado.")
        }

        val senhaHash = hashSenha(senhaPura)

        return try {
            val dbHelper = DatabaseHelper(context)
            val db = dbHelper.writableDatabase

            val values = ContentValues().apply {
                put("nome", nome)
                put("email", email)
                put("senha", senhaHash)
                put("curso", curso)
                put("turma", turma)
                val agora = System.currentTimeMillis().toString()
                put("criado_em", agora)
                put("atualizado_em", agora)
            }

            db.insertOrThrow("User", null, values)
            db.close()
            true
        } catch (e: Exception) {
            e.printStackTrace()
            false
        }
    }

    fun verificarLogin(email: String, senhaDigitada: String): Boolean {
        val usuario = buscarUsuarioPorEmail(email)
        return usuario != null && usuario.senha == hashSenha(senhaDigitada)
    }

    fun buscarUsuarioPorEmail(email: String): Usuario? {
        val dbHelper = DatabaseHelper(context)
        val db = dbHelper.readableDatabase

        val cursor = db.rawQuery(
            "SELECT nome, email, senha, curso, turma, criado_em, atualizado_em FROM User WHERE email = ?",
            arrayOf(email)
        )

        var usuario: Usuario? = null
        if (cursor.moveToFirst()) {
            usuario = Usuario(
                nome = cursor.getString(0),
                email = cursor.getString(1),
                senha = cursor.getString(2),
                curso = cursor.getString(3),
                turma = cursor.getString(4),
                criadoEm = cursor.getString(5),
                atualizadoEm = cursor.getString(6)
            )
        }

        cursor.close()
        db.close()
        return usuario
    }

    fun listarUsuarios(): List<Usuario> {
        val dbHelper = DatabaseHelper(context)
        val db = dbHelper.readableDatabase

        val cursor = db.rawQuery("SELECT nome, email, senha, curso, turma, criado_em, atualizado_em FROM User", null)

        val usuarios = mutableListOf<Usuario>()
        while (cursor.moveToNext()) {
            usuarios.add(
                Usuario(
                    nome = cursor.getString(0),
                    email = cursor.getString(1),
                    senha = cursor.getString(2),
                    curso = cursor.getString(3),
                    turma = cursor.getString(4),
                    criadoEm = cursor.getString(5),
                    atualizadoEm = cursor.getString(6)
                )
            )
        }

        cursor.close()
        db.close()
        return usuarios
    }

    fun atualizarUsuario(nome: String, email: String, senha: String, curso: String, turma: String) {
        val dbHelper = DatabaseHelper(context)
        val db = dbHelper.writableDatabase

        val values = ContentValues().apply {
            put("nome", nome)
            put("senha", senha)
            put("curso", curso)
            put("turma", turma)
            val agora = System.currentTimeMillis().toString()
            put("atualizado_em", agora)
        }

        db.update("User", values, "email = ?", arrayOf(email))
        db.close()
    }
}
