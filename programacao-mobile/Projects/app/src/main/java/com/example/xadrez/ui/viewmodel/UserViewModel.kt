package com.example.xadrez.ui.viewmodel

import androidx.lifecycle.ViewModel
import com.example.xadrez.model.Usuario
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow


class UserViewModel : ViewModel() {
    private val _usuarioLogado = MutableStateFlow<Usuario?>(null)
    val usuarioLogado: StateFlow<Usuario?> = _usuarioLogado

    fun setUsuario(usuario: Usuario?) {
        _usuarioLogado.value = usuario
    }

    fun limparUsuario() {
        _usuarioLogado.value = null
    }
}
