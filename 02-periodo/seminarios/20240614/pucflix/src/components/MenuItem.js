export default function MenuItem(props){
    
    return (
        <li>
            <img src= {props.imagem}/>
            <a href={props.url}>{props.titulo}</a>
        </li>
    );
}