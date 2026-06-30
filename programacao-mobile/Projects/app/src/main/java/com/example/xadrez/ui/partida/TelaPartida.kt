package com.example.xadrez.ui.partida

import android.widget.Toast
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.EmojiEvents
import androidx.compose.material.icons.filled.Pause
import androidx.compose.material.icons.filled.PlayArrow
import androidx.compose.material.icons.filled.Stop
import androidx.compose.material.icons.filled.RemoveCircle
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.ExposedDropdownMenuBox
import androidx.compose.material3.Icon
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.OutlinedTextFieldDefaults
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import com.example.xadrez.repository.UserRepository
import com.example.xadrez.repository.PartidaRepository
import com.example.xadrez.ui.viewmodel.UserViewModel
import kotlinx.coroutines.delay

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun TelaPartida(navController: NavController, userViewModel: UserViewModel) {
    val context = LocalContext.current
    val userRepo = remember { UserRepository(context) }
    val partidaRepo = remember { PartidaRepository(context) }

    val usuario by userViewModel.usuarioLogado.collectAsState()
    val nomeJogador1 = usuario?.nome ?: "Jogador 1"
    val emailJogador1 = usuario?.email ?: ""

    var adversario by remember { mutableStateOf("") }
    var nomeJogador2 by remember { mutableStateOf("") }

    var tempoJogador1 by remember { mutableStateOf(300) }
    var tempoJogador2 by remember { mutableStateOf(300) }
    var ativoJogador1 by remember { mutableStateOf(true) }
    var rodando by remember { mutableStateOf(false) }

    val usuarios = remember { userRepo.listarUsuarios() }
    val filtrados = usuarios
        .filter { it.email != emailJogador1 }
        .filter { it.nome.contains(adversario, ignoreCase = true) }

    var expanded by remember { mutableStateOf(false) }

    LaunchedEffect(rodando, ativoJogador1) {
        while (rodando) {
            delay(1000)
            if (ativoJogador1) {
                if (tempoJogador1 > 0) tempoJogador1--
            } else {
                if (tempoJogador2 > 0) tempoJogador2--
            }
        }
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFF121212))
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {

        Spacer(modifier = Modifier.height(64.dp))

        ExposedDropdownMenuBox(
            expanded = expanded,
            onExpandedChange = { expanded = !expanded }
        ) {
            OutlinedTextField(
                value = adversario,
                onValueChange = {
                    adversario = it
                    expanded = true
                },
                label = { Text("Buscar Jogador", color = Color.White) },
                modifier = Modifier
                    .menuAnchor()
                    .fillMaxWidth(),
                shape = RoundedCornerShape(12.dp),
                colors = OutlinedTextFieldDefaults.colors(
                    focusedBorderColor = Color(0xFFBB86FC),
                    unfocusedBorderColor = Color.Gray,
                    focusedLabelColor = Color(0xFFBB86FC),
                    unfocusedLabelColor = Color.White,
                    cursorColor = Color(0xFFBB86FC),
                    focusedTextColor = Color.White,
                    unfocusedTextColor = Color.LightGray
                )
            )

            ExposedDropdownMenu(
                expanded = expanded,
                onDismissRequest = { expanded = false }
            ) {
                filtrados.forEach { usuario ->
                    DropdownMenuItem(
                        text = { Text("${usuario.nome} - ${usuario.email}") },
                        onClick = {
                            adversario = usuario.email
                            nomeJogador2 = usuario.nome
                            expanded = false
                        }
                    )
                }
            }
        }

        Spacer(modifier = Modifier.height(24.dp))

        Row(
            modifier = Modifier.fillMaxWidth(),
            horizontalArrangement = Arrangement.SpaceEvenly
        ) {
            Button(
                onClick = {
                    if (nomeJogador2.isEmpty()) {
                        Toast.makeText(context, "Selecione um adversário antes de iniciar!", Toast.LENGTH_LONG).show()
                    } else {
                        rodando = true }
                },
                modifier = Modifier.size(80.dp),
                shape = RoundedCornerShape(16.dp),
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color.DarkGray,
                    contentColor = Color.White
                )
            ) {
                Icon(Icons.Filled.PlayArrow, contentDescription = "Play", modifier = Modifier.size(40.dp))
            }

            Button(
                onClick = { rodando = false },
                modifier = Modifier.size(80.dp),
                shape = RoundedCornerShape(16.dp),
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color.DarkGray,
                    contentColor = Color.White
                )
            ) {
                Icon(Icons.Filled.Pause, contentDescription = "Pause", modifier = Modifier.size(40.dp))
            }

            Button(
                onClick = {
                    rodando = false
                    tempoJogador1 = 300
                    tempoJogador2 = 300
                },
                modifier = Modifier.size(80.dp),
                shape = RoundedCornerShape(16.dp),
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color.DarkGray,
                    contentColor = Color.White
                )
            ) {
                Icon(Icons.Filled.Stop, contentDescription = "Stop", modifier = Modifier.size(40.dp))
            }

            Button(
                onClick = { navController.navigate("principal") {
                        popUpTo("partida") { inclusive = true }
                    }
                },
                modifier = Modifier.size(80.dp),
                shape = RoundedCornerShape(16.dp),
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color.DarkGray,
                    contentColor = Color.White
                )
            ) {
                Icon(Icons.Filled.RemoveCircle, contentDescription = "Sair", modifier = Modifier.size(40.dp))
            }
        }

        Spacer(modifier = Modifier.height(32.dp))

        // Botão Vitória Jogador 1
        Button(
            onClick = {
                if (nomeJogador2.isEmpty()) {
                    Toast.makeText(context, "Selecione um adversário antes de iniciar!", Toast.LENGTH_LONG).show()
                } else {
                    partidaRepo.inserirPartida(nomeJogador1, nomeJogador2, nomeJogador1)
                    navController.navigate("principal") {
                        popUpTo("partida") { inclusive = true }
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth()
                .height(60.dp),
            shape = RoundedCornerShape(12.dp),
            colors = ButtonDefaults.buttonColors(
                containerColor = Color(0xFF6200EE),
                contentColor = Color.White
            )
        ) {
            Icon(Icons.Filled.EmojiEvents, contentDescription = "Vitória $nomeJogador1")
            Spacer(modifier = Modifier.width(8.dp))
            Text("Vitória $nomeJogador1", fontWeight = FontWeight.Bold)
        }

        Spacer(modifier = Modifier.height(16.dp))

        // Relógio Jogador 1
        Button(
            onClick = { ativoJogador1 = false },
            modifier = Modifier
                .fillMaxWidth()
                .height(180.dp),
            shape = RoundedCornerShape(16.dp),
            colors = ButtonDefaults.buttonColors(
                containerColor = if (rodando && ativoJogador1) Color.Green else Color.DarkGray,
                contentColor = Color.White
            )
        ) {
            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                Text(nomeJogador1, fontSize = 26.sp, fontWeight = FontWeight.Bold)
                Spacer(modifier = Modifier.height(12.dp))
                Text(
                    text = "${tempoJogador1 / 60}:${(tempoJogador1 % 60).toString().padStart(2, '0')}",
                    fontSize = 36.sp,
                    fontWeight = FontWeight.Bold
                )
            }
        }

        Spacer(modifier = Modifier.height(32.dp))

        // Relógio Jogador 2
        Button(
            onClick = { ativoJogador1 = true },
            modifier = Modifier
                .fillMaxWidth()
                .height(180.dp),
            shape = RoundedCornerShape(16.dp),
            colors = ButtonDefaults.buttonColors(
                containerColor = if (rodando && !ativoJogador1) Color.Green else Color.DarkGray,
                contentColor = Color.White
            )
        ) {
            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                Text(nomeJogador2.ifEmpty { "Adversário" }, fontSize = 26.sp, fontWeight = FontWeight.Bold)
                Spacer(modifier = Modifier.height(12.dp))
                Text(
                    text = "${tempoJogador2 / 60}:${(tempoJogador2 % 60).toString().padStart(2, '0')}",
                    fontSize = 36.sp,
                    fontWeight = FontWeight.Bold
                )
            }
        }

        Spacer(modifier = Modifier.height(16.dp))

        // Botão Vitória Jogador 2
        Button(
            onClick = {
                if (nomeJogador2.isEmpty()) {
                    Toast.makeText(context, "Selecione um usuário antes de iniciar!", Toast.LENGTH_LONG).show()
                } else {
                    partidaRepo.inserirPartida(nomeJogador1, nomeJogador2, nomeJogador2)
                    navController.navigate("principal") {
                        popUpTo("partida") { inclusive = true }
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth()
                .height(60.dp),
            shape = RoundedCornerShape(12.dp),
            colors = ButtonDefaults.buttonColors(
                containerColor = Color(0xFF6200EE),
                contentColor = Color.White
            )
        ) {
            Icon(Icons.Filled.EmojiEvents, contentDescription = "Vitória $nomeJogador2")
            Spacer(modifier = Modifier.width(8.dp))
            Text(if (nomeJogador2.isEmpty()) { "Vitória Adversário" } else { "Vitória $nomeJogador2"}, fontWeight = FontWeight.Bold)
        }
    }
}