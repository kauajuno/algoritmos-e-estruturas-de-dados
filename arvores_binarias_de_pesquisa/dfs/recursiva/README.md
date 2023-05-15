# DFS Recursiva

A DFS recursiva é a forma mais simples e legível de se fazer as DFSs de uma árvore binária. Entretanto, é relativamente ineficaz se comparada com a forma iterativa em razão da sobrecarga de chamadas de função gerada. Em casos muito extremos com árvores de altura muito, mas muito grandes, a DFS recursiva poderia gerar um stack overflow.

A legibilidade se dá em razão do código ser muito parecido com a explicação que se dá de fato falando. As chamadas seguem um padrão muito simples e a condição de parada para a recursividade torna tudo muito fácil. Seguem pseudoalgoritmos de como essas funções funcionam. Partindo do pressuposto que a primeira chamada sempre é feita passando a raiz da árvore:

## Preorder

```
inorder(node)
    if (node == empty) return
    inorder(node->esquerda)
    print(node->valor)
    inorder(node->direita)
```

```
preorder(node)
    if (node == empty) return
    print(node->valor)
    preorder(node->esquerda)
    preorder(node->direita)
```

```
postorder(node)
    if (node == empty) return
    postorder(node->esquerda)
    postorder(node->direita)
    print(node->valor)
```

Repare como a única coisa que muda para fazer todos esses caminhos diferentes é a posição da chamada das funções em relação ao momento em que o valor é lido.