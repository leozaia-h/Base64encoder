# Base64encoder

O código inteiro foi escrito por mim, exceto a função ```int_to_bin``` que eu peguei [aqui](https://stackoverflow.com/questions/5488377/converting-an-integer-to-binary-in-c).

O programa vai lhe mostrar:
> O caractere em forma decimal na tabela ascii.

> Sua representação em binário.

> Sua representação na tabela base64.

> A string em base64.

<ul>
<li>Por conta da biblioteca <math.h>, compile assim:</li>
<ul>
  
```gcc encode.c -o encode -lm```
