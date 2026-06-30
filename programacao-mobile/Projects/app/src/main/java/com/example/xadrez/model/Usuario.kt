package com.example.xadrez.model

data class Usuario(
    val nome: String,
    val email: String,
    val senha: String,
    val curso: String,
    val turma: String,
    val criadoEm: String? = null,
    val atualizadoEm: String? = null
)