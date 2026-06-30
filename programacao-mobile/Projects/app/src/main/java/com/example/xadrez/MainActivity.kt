package com.example.xadrez

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.runtime.Composable
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

import com.example.xadrez.ui.login.TelaLogin
import com.example.xadrez.ui.cadastro.TelaCadastro
import com.example.xadrez.ui.principal.TelaPrincipal
import com.example.xadrez.ui.partida.TelaPartida
import com.example.xadrez.ui.perfil.TelaPerfil
import com.example.xadrez.ui.configuracoes.TelaConfiguracoes
import com.example.xadrez.ui.sobre.TelaSobre
import com.example.xadrez.ui.viewmodel.UserViewModel

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            AppNavigation()
        }
    }
}

@Composable
fun AppNavigation() {
    val navController = rememberNavController()
    val userViewModel: UserViewModel = viewModel()

    NavHost(navController, startDestination = "login") {
        composable("login") { TelaLogin(navController, userViewModel) }
        composable("cadastro") { TelaCadastro(navController, userViewModel) }
        composable("principal") { TelaPrincipal(navController, userViewModel) }
        composable("partida") { TelaPartida(navController, userViewModel) }
        composable("perfil") { TelaPerfil(navController, userViewModel) }
        composable("configuracoes") { TelaConfiguracoes(navController, userViewModel) }
        composable("sobre") { TelaSobre(navController) }

    }
}

