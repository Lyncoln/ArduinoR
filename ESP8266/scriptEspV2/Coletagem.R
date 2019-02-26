library(rvest)
library(tidyverse)
library(lubridate)

caminhoTemp = "//*[@id='temperatura']"

extrair = function(caminho){
  pagina =  read_html("http://192.168.1.105/")
  dados = pagina %>% 
    html_node(xpath = caminho) %>% 
    html_text() %>% 
    str_extract("\\d+")
  return(dados)
}




setwd("F://GitHub//Sensores-Arduino//ESP8266//scriptEspV2")
cont = 0 
while(T){
  data = as.character(now())
  valor = extrair(caminhoTemp)
  cat(paste(data," ; "),file="dados.txt",append = TRUE)
  cat(valor,file="dados.txt", sep = "\n",append=TRUE)
  cont = cont+1
  print(cont)
  Sys.sleep(3)
}


BD = tibble()
BD = BD %>% 
  mutate(horario = NA, dados = NA)
extracao = function(caminho,bancoDados){
  while(T){
    data = as.character(now())
    valor = extrair(caminho)
    bancoDados = bancoDados %>% 
      add_row(horario = data, dados = valor)
    Sys.sleep(3)
    print("Peguei")
    return(bancoDados)
  }
  
}
while(T){
  data = as.character(now())
  valor = extrair(caminhoTemp)
  BD = BD %>% 
    add_row(horario = data, dados = valor)
  print("Peguei")
  Sys.sleep(60)
}