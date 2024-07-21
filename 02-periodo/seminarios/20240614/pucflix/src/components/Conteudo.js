import Filme from "./Filme";

export default function Conteudo(props) {
  return (
    <ul class="conteudo">
      {
        props.lista.map( (item) => <Filme nome = {item.nome} imagem={item.imagem} /> )
      }     
    </ul>
  );
}
