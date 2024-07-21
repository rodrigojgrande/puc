import ReactDOM from 'react-dom';
import Topo from './components/Topo';
import Menu from './components/Menu';
import Conteudo from './components/Conteudo';

function App(){
  return( 
  <div>
    <Topo/>

		<div class="row">
    <Menu/>
    <Conteudo/>

		</div>
  </div>
  ) 
}

const elementoRoot = document.querySelector('#root');
ReactDOM.render(<App />, elementoRoot);