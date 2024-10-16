// alert('Deu certo');

/*
let receita1 = prompt('Digite a receita 1');
let receita2 = prompt('Digite a receita 2');
let receita3 = prompt('Digite a receita 3');
let receita4 = prompt('Digite a receita 4');
*/

// const receitas = [
//     'frango',
//     'peixe',
//     'carne'
// ];

const receitas = [];

/*
console.log(receita1);
console.log(receita2);
console.log(receita3);
console.log(receita4);
*/

// receitas[0] = prompt('Digite a receita 1');
// receitas[1] = prompt('Digite a receita 2');
// receitas[2] = prompt('Digite a receita 3');


// receitas.push(prompt('Digite a receita 1'));
// receitas.push(prompt('Digite a receita 2'));
// receitas.push(prompt('Digite a receita 3'));

// let qtdReceitas = prompt('Qual a quantidade de receitas vc quer digitar?');

let titulo = prompt('Digite o titulo da receita:');
let ingrediente = prompt('Digite o ingrediente da receita:');
let preparo = prompt('Digite o preparo da receita:');

receitas.push(titulo);
receitas.push(ingrediente);
receitas.push(preparo);

const receita = [titulo, ingrediente, preparo];


// Enquanto a qtde de receitas não for digitada, repita o código
// while (a qtde de receitas não for digitada) {repita o código}

// let contador = 0;
// while (contador < qtdReceitas) {
//     receitas.push(prompt('Digite a receita:'));
//     // contador = contador + 1;
//     contador ++;
// }

console.log(receitas);

// 1 - Buscar o elemento lista no DOM e trazer para o js
const lista = document.querySelector('ul');

lista.innerHTML = `${lista.innerHTML}`

console.log(lista);

// 2 - Adicionar minha receita na lista

// lista.innerHTML = lista.innerHTML + '<li>'+receita2+'</li>';
// lista.innerHTML = lista.innerHTML + '<li>'+receita3+'</li>';

/*
lista.innerHTML = `${lista.innerHTML} <li>${receita1}</li>`;
lista.innerHTML = `${lista.innerHTML} <li>${receita2}</li>`;
lista.innerHTML = `${lista.innerHTML} <li>${receita3}</li>`;
lista.innerHTML = `${lista.innerHTML} <li>${receita4}</li>`;
*/

// lista.innerHTML = `${lista.innerHTML} <li>${receitas[0]}</li>`;
// lista.innerHTML = `${lista.innerHTML} <li>${receitas[1]}</li>`;
// lista.innerHTML = `${lista.innerHTML} <li>${receitas[2]}</li>`;

// contador = 0;
// while(contador < qtdReceitas){
//     lista.innerHTML = `${lista.innerHTML} <li>${receitas[contador]}</li>`;
//     contador ++;
// }
