const formulário = document.querySelector("form");
let people = JSON.parse(localStorage.getItem("peopleList")) || Array();

people.map(person => adicionarAoDOM(person));

formulário.addEventListener("submit", evento => {
    evento.preventDefault();
    let name = document.querySelector("#name").value;
    let age = parseInt(document.querySelector("#age").value);
    let person = {name, age};
    people.push(person);
    updateStorage();
    adicionarAoDOM(person);
});

function findPerson(personName){
    return people.find(current => current.name === personName);
}

function maioresDeIdade(){
    return people.filter(person => person.age >= 18);
}

function parseIdade(){
    return people.map(person => ({name: person.name, age: parseInt(person.age)}));
}

function médiaIdade(){
    return people.reduce((acc, person) => acc + person.age, 0)/people.length;
}

function removeDaLista(person){
    let index = people.findIndex(p => p.name === person.name && p.age === person.age);
    people.splice(index, 1);
}

function updateStorage(){
    localStorage.setItem("peopleList", JSON.stringify(people));
}

function adicionarAoDOM(pessoa){
    let seção = document.querySelector("#resultados");
    let div = document.createElement("div");
    let nome = document.createElement("h2");
    let idade = document.createElement("span");

    let btnRemove = document.createElement("button");

    nome.innerText = pessoa.name;
    idade.innerText = pessoa.age;
    btnRemove.innerText = "Excluir";

    btnRemove.addEventListener("click", event => {
        seção.removeChild(div);
        removeDaLista(pessoa);
        updateStorage();
    });

    div.appendChild(nome);
    div.appendChild(idade);
    div.appendChild(btnRemove);
    seção.appendChild(div);
}