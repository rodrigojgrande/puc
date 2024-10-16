const formulário = document.querySelector("form");
formulário.addEventListener("submit", minhaSubmissão);

function minhaSubmissão(evento){
    evento.preventDefault();
    console.log("Formulário submetido");

    let name = document.querySelector("#name").value;
    console.log(name);

    let age = document.querySelector("#age").value;
    console.log(age);

    let person = {name, age};
    adicionarAoDOM(person);
}

function adicionarAoDOM(pessoa){
    let seção = document.querySelector("#resultados");
    let div = document.createElement("div");
    let nome = document.createElement("h2");
    let idade = document.createElement("span");

    nome.innerText = pessoa.name;
    idade.innerText = pessoa.age;

    div.appendChild(nome);
    div.appendChild(idade);
    seção.appendChild(div);
}