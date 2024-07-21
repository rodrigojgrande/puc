import MenuItem from "./MenuItem";

export default function Menu() {
  return (
    <ul class="menu">
      <MenuItem url="home.html" imagem="https://www.seekpng.com/png/full/375-3752606_homepage-icon-house-logo-png-white.png" titulo="Home" />
      <MenuItem url="favoritos.html" titulo="Favoritos" imagem="https://icon-library.com/images/white-heart-icon-png/white-heart-icon-png-11.jpg"/> 
      <MenuItem url="contatos.html" imagem="https://i.im.ge/2022/09/15/1X4f74.envelope.png" titulo="Contatos"/>
    </ul>
  );
}
