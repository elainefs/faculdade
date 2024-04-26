function validaBusca() {
  if (document.querySelector("#q").value == "") {
    document.querySelector("#form-busca").style.background = "red";
    return false;
  }
}

document.querySelector("#form-busca").onsubmit = validaBusca;
