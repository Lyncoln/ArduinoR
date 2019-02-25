library(rvest)
library(tidyverse)
library(lubridate)

caminhoTemp = "//*[@id='temperatura']"

extrair = function(caminho){
  pagina =  read_html("http://192.168.1.106/")
  dados = pagina %>% 
    html_node(xpath = caminho) %>% 
    html_text() %>% 
    str_extract("\\d+")
  return(dados)
}
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




BD = tibble()
BD = BD %>% 
  mutate(horario = NA, dados = NA)

while(T){
  data = as.character(now())
  valor = extrair(caminhoTemp)
  BD = BD %>% 
    add_row(horario = data, dados = valor)
  print("Peguei")
  Sys.sleep(60)
}

setwd("F://GitHub//Sensores-Arduino//ESP8266//scriptEsp")
while(T){
  data = as.character(now())
  valor = extrair(caminhoTemp)
  cat(paste(data," ; "),file="outfile.txt",append = TRUE)
  cat(valor,file="outfile.txt", sep = "\n",append=TRUE)
  print("Peguei")
  Sys.sleep(2)
}


