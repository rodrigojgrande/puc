
import java.io.File;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.file.Files;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class CalculoHash {

    public static String calculaHashEntradaTexto(String texto, String tipoHash)
            throws NoSuchAlgorithmException, UnsupportedEncodingException {
        MessageDigest algoritmoHash;
        byte mensagemCriptografada[];
        StringBuilder hashHexadecimal;
        String hashHexadecimalSaida;

        algoritmoHash = MessageDigest.getInstance(tipoHash);
        mensagemCriptografada = algoritmoHash.digest(texto.getBytes("UTF-8"));
        hashHexadecimal = new StringBuilder();
        for (byte b : mensagemCriptografada) {
            hashHexadecimal.append(String.format("%02X", 0xFF & b));
        }

        hashHexadecimalSaida = hashHexadecimal.toString();
        return hashHexadecimalSaida;
    }

    @SuppressWarnings("UnusedAssignment")
    public static String calculaHashEntradaArquivo(String nomeArquivo, String tipoHash)
            throws NoSuchAlgorithmException, UnsupportedEncodingException, IOException {
        MessageDigest algoritmoHash;
        byte bytesEntrada[], mensagemCriptografada[];
        StringBuilder hashHexadecimal;
        String hashHexadecimalSaida;
        File arquivo;

        arquivo = new File(nomeArquivo);
        if (arquivo.exists()) {
            algoritmoHash = MessageDigest.getInstance(tipoHash);
            bytesEntrada = Files.readAllBytes(arquivo.toPath());
            algoritmoHash = MessageDigest.getInstance(tipoHash);
            mensagemCriptografada = algoritmoHash.digest(bytesEntrada);

            hashHexadecimal = new StringBuilder();
            for (byte b : mensagemCriptografada) {
                hashHexadecimal.append(String.format("%02X", 0xFF & b));
            }
            hashHexadecimalSaida = hashHexadecimal.toString();
            return hashHexadecimalSaida;
        }
        return "HASH NAO CALCULADA";
    }

    public static void main(String args[])
            throws NoSuchAlgorithmException, UnsupportedEncodingException, IOException {
        String hashTexto, hashArquivo256, hashArquivo512;

        hashTexto = calculaHashEntradaTexto("admin", "MD5");
        System.out.println("Hash MD5 de Entrada de Texto = " + hashTexto);
        hashArquivo256 = calculaHashEntradaArquivo("hellokitty.jpg", "SHA-256");
        System.out.println("Hash SHA-256 de Arquivo = " + hashArquivo256);
        hashArquivo512 = calculaHashEntradaArquivo("hellokitty.jpg", "SHA-512");
        System.out.println("Hash SHA-512 de Arquivo = " + hashArquivo512);
    }
}
