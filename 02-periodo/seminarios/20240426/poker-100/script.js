let qtdeJogadores;
let jogo;

function finalizar(){
    const painel = document.querySelector('.selecionar-jogo');
    painel.classList.add('escondido');

    const loading = document.querySelector('.loading-overlay');
    loading.classList.remove('escondido');

    const paragrafo = document.querySelector('.mensagem-iniciando');
    paragrafo.innerHTML = 'INICIANDO POKER 100 com o jogo ' + jogo + ' qtde. jogadores '+ qtdeJogadores;
}
function selecionarQtdeJogadores(botao){ 
    
    const botaoSelecionado = document.querySelector('.qtd-jogadores .selecionado');
    if (botaoSelecionado !== null){
        botaoSelecionado.classList.remove('selecionado');
    }
    
    // 2 - alterar o elemento
    botao.classList.add('selecionado');

    qtdeJogadores = botao.innerHTML;
}

function selecionarJogo(botaoClicado){
    const seletor = '.'+botaoClicado;
    
    // 1 - buscar o botao que foi selecionado anteriormente
    const botaoAnterior = document.querySelector('.selecionar-jogo .selecionado');

    // 2 - verificar se existe algum elemento com a classe selecionado
    if ( botaoAnterior !== null ) {   
        // 2.1 - remover a classe selecionado
        botaoAnterior.classList.remove('selecionado');
    }

    // 3 - buscar o botao cliado e trazer para o js 
    const botaoSelecionado = document.querySelector(seletor);
    // 4 - adicionar a classe selecionado no botao clicado
    botaoSelecionado.classList.add('selecionado');

    jogo = botaoSelecionado.innerHTML;
}

// javascrit crie uma funcao perguntarIdade
function perguntarIdade(){

    const anoNacimento = Number(prompt('Ano de Nascimento'));
    const idade = 2024 - anoNacimento;

   //SE a idade for menor que 18
   if( idade < 18){
        // busque no documento html o paragrafo com a classe aviso

        // 1 - Pegar o elemento no html e trazer para o JS
        const paragrafo = document.querySelector('.aviso');
        // 2 - alterar o conteudo trocar o texto do paragrafo
        paragrafo.innerHTML = 'Ops! Voce tem idade '+idade+' voce não pode jogar!';
   } else { 
        // 1 - Buscar o elemento (link) no html e trazer para o JS
        const painel  = document.querySelector('.selecionar-jogo');
        // 2 - Acessar a lista de Classes CSS e remover a classe escondido
        painel.classList.remove('escondido');
    }   
}