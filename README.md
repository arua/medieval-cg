# BATALHA MEDIEVAL
NÃO É MAIS VELHO-OESTE

# Como clonar esse repositório
[https://confluence.atlassian.com/pages/viewpage.action?pageId=270827678]  
Siga os passos 2, 3, 4 e 6 do link, depois execute na linha de comando:  

	git clone git@bitbucket.org:Hueho/medieval-cg.git

Uma pasta mágica chamada medieval-cg deverá se materializar.

# Não sei usar o Git!!!11!

Leia: [http://git-scm.com/documentation]

# Como compilar

Abra a pasta no terminal, use o comando "make" para compilar, "make clean" para recompilar do zero.

# Que pastas são essas?

***src/***: colocaremos o código-fonte aqui  
***resources/***: colocaremos texturas, imagens e o escambau aqui  
***bin/***: aqui vai ficar o executável depois de compilado  

# Que "Makefile" é esse?

Um arquivo pro programa "make" utilizar que fala quais arquivos devem ser compilados e linkados, e que torna nossa vida mais feliz se a gente quiser fazer o programa usando mais do que um arquivo em C

# Porquê não esperou a gente?

Porque sou afobado.

# Que "README.md" é esse?

O "leia-me" que você está lendo, em formato bruto de Markdown. Sintaxe é uma porcaria (mas o Gedit tem suporte nativo pelo menos). Detalhes de como escrever aqui: [http://daringfireball.net/projects/markdown/]

# Comandos do Git

git branch: lista todas as branchs locais.  
git branch <nome>: cria uma branch local com o nome passado.  
git checkout <nome>: muda para a branch com o nome passado.  
git pull: pega os últimos commits do master.  
git add . : adiciona todas as mudanças ao commit, tirando arquivos deletados.  
git add -u: adiciona mudanças que deletam arquivos.  
git commit: faz um commit.  
git rebase -i master: faz rebase interativo com base na branch master.  
git mergetool: se um rebase falhar, use para fazer o merge de cada arquivo com conflito.  
git rebase --continue: depois do merge dar certo, use para prosseguir com o rebase anterior.  
git rebase --abort: se quiser desistir do rebase, use para abortar.  
git push: manda os commits feitos pro master remoto (i.e o repositório)