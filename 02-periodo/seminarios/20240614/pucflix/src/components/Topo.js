import { useState } from "react";

export default function Topo() {

  let [imagem, setImagem] = useState('https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQbDexwez6fwjsz-N3lcR3P5xcQH5enbLr9Og&usqp=CAU');
    
  // const nome = prompt("Qual é o seu nome?");

  // let nome = ''; // Variavel normal

  // Criar uma variavel de estado
  let [nome, setNome] = useState(''); // Variavel de estado

  function inserirNome(){
    // nome = prompt('Digite seu nome');
    // console.log('executou a função')

    let nomeDigitado = prompt('Digite seu nome');
    setNome(nomeDigitado);
  }

  function trocarImagem(){
    const novaImagem = prompt("URL da Imagem");
    setImagem(novaImagem);
  }

    return (
      <div class="topo">
        <h1>PUCFlix</h1>
        <div>
          <button onClick={inserirNome}>Inserir Nome</button>
          <p>{
            ( nome !== undefined && nome !== '' && nome !== null) ? 
              `Bem-vindo(a), ${nome}` 
            : 
              'Bem-vindo(a)'
          }!</p>
          <img onClick={trocarImagem} src={imagem} />
        </div>
      </div>
    );
  }
