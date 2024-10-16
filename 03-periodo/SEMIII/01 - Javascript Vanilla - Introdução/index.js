let parágrafo = document.querySelector("#desc");
parágrafo.innerText = "Texto alterado via Javascript";

const formulário = document.querySelector("form");
formulário.addEventListener("submit", minhaSubmissão);

function minhaSubmissão(evento){
    evento.preventDefault();
    console.log("Formulário submetido");

    let name = document.querySelector("#name").value;
    console.log(name);

    let age = document.querySelector("#age").value;
    console.log(age);
}