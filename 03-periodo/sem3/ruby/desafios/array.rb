# ARRAY
numeros = [1,2,3,4,5,6,10]
numeros.push(100) # Adiciona ao fim do array
p "Push"
p numeros.last # Acessa o ultimo item do array
ultimo_numero = numeros.pop
p "Pop"
p ultimo_numero
p numeros
primeiro_numero = numeros.shift # Tira o primeiro item do array
p "shift"
p ultimo_numero
p numeros
numeros.unshift(0) # Coloca um item no começo do array
p "Unshift"
p numeros

# ARRAY MULTIDIMENSIONAL
pessoa = [["Aluan", 35, "Poços de Caldas"], []]
pessoa[0][1]