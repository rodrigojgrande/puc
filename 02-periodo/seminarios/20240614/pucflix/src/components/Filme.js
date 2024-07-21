export default function Filme(props){
    return (
        <li class="filme">
            <img src={props.imagem} alt={props.nome} />
            <p>{props.nome}</p>
        </li>
    );
}