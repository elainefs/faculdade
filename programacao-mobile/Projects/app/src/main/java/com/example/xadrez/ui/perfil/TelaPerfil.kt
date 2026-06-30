package com.example.xadrez.ui.perfil

import android.widget.Toast
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Visibility
import androidx.compose.material.icons.filled.VisibilityOff
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.OutlinedTextFieldDefaults
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.input.PasswordVisualTransformation
import androidx.compose.ui.text.input.VisualTransformation
import com.example.xadrez.model.Usuario
import com.example.xadrez.repository.UserRepository
import com.example.xadrez.ui.viewmodel.UserViewModel

@Composable
fun TelaPerfil(navController: NavController, userViewModel: UserViewModel) {
    val context = LocalContext.current
    val userRepo = remember { UserRepository(context) }
    val usuario by userViewModel.usuarioLogado.collectAsState()
    var senhaVisivel by remember { mutableStateOf(false) }

    var nome by remember { mutableStateOf(usuario?.nome ?: "") }
    var email by remember { mutableStateOf(usuario?.email ?: "") }
    var senha by remember { mutableStateOf("") }
    var curso by remember { mutableStateOf(usuario?.curso ?: "") }
    var turma by remember { mutableStateOf(usuario?.turma ?: "") }

    Box(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFF121212)),
        contentAlignment = Alignment.Center
    ) {
        Column(
            modifier = Modifier
                .padding(16.dp)
                .background(Color(0xFF1E1E1E), RoundedCornerShape(16.dp))
                .padding(24.dp),
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            Text(
                text = "Alterar Dados",
                fontSize = 26.sp,
                fontWeight = FontWeight.Bold,
                color = Color.White
            )

            Spacer(modifier = Modifier.height(16.dp))

            OutlinedTextField(
                value = nome,
                onValueChange = { nome = it },
                label = { Text("Nome completo") },
                singleLine = true,
                modifier = Modifier.fillMaxWidth(),
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

            Spacer(modifier = Modifier.height(12.dp))

            OutlinedTextField(
                value = email,
                onValueChange = { },
                label = { Text("E-mail (não editável)") },
                singleLine = true,
                enabled = false,
                modifier = Modifier.fillMaxWidth(),
                colors = OutlinedTextFieldDefaults.colors(
                    disabledBorderColor = Color.Gray,
                    disabledTextColor = Color.LightGray,
                    disabledLabelColor = Color.White
                )
            )

            Spacer(modifier = Modifier.height(12.dp))

            OutlinedTextField(
                value = senha,
                onValueChange = { senha = it },
                label = { Text("Senha") },
                singleLine = true,
                visualTransformation = if (senhaVisivel) VisualTransformation.None else PasswordVisualTransformation(),
                trailingIcon = {
                    val imagem = if (senhaVisivel) Icons.Default.Visibility else Icons.Default.VisibilityOff
                    IconButton(onClick = { senhaVisivel = !senhaVisivel }) {
                        Icon(imageVector = imagem, contentDescription = if (senhaVisivel) "Ocultar senha" else "Mostrar Senha")
                    }
                },
                modifier = Modifier.fillMaxWidth(),
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
            Text(
                text = "Deixe em branco para manter a senha atual",
                color = Color.Gray,
                fontSize = 12.sp,
                modifier = Modifier.align(Alignment.Start).padding(top = 4.dp)
            )

            Spacer(modifier = Modifier.height(12.dp))

            OutlinedTextField(
                value = curso,
                onValueChange = { curso = it },
                label = { Text("Curso") },
                singleLine = true,
                modifier = Modifier.fillMaxWidth(),
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

            Spacer(modifier = Modifier.height(12.dp))

            OutlinedTextField(
                value = turma,
                onValueChange = { turma = it },
                label = { Text("Turma") },
                singleLine = true,
                modifier = Modifier.fillMaxWidth(),
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

            Spacer(modifier = Modifier.height(20.dp))

            Button(
                onClick = {
                    val senhaFinal = if (senha.isNotEmpty()) {
                        userRepo.hashSenha(senha)
                    } else {
                        usuario?.senha ?: ""
                    }

                    val usuarioAtualizado = Usuario(
                        nome = nome,
                        email = email,
                        senha = senhaFinal,
                        curso = curso,
                        turma = turma
                    )

                    userRepo.atualizarUsuario(nome, email, senhaFinal, curso, turma)
                    userViewModel.setUsuario(usuarioAtualizado)

                    Toast.makeText(context, "Usuário atualizado.", Toast.LENGTH_LONG).show()

                    navController.navigate("principal") {
                        popUpTo("perfil") { inclusive = true }
                    }
                },
                modifier = Modifier.fillMaxWidth(),
                shape = RoundedCornerShape(12.dp),
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color(0xFF6200EE),
                    contentColor = Color.White
                )
            ) {
                Text("Salvar")
            }

            Spacer(modifier = Modifier.height(12.dp))

            OutlinedButton(
                onClick = { navController.navigate("configuracoes") },
                shape = RoundedCornerShape(12.dp),
                modifier = Modifier.fillMaxWidth(),
                colors = ButtonDefaults.outlinedButtonColors(
                    contentColor = Color.White
                )
            ) {
                Text("Cancelar",
                    fontSize = 15.sp)
            }
        }
    }
}
