void plot_cr() {
    // Cria uma "tela" para o gráfico
    TCanvas *c1 = new TCanvas("c1", "Perfil de Raios Cosmicos", 800, 600);
    
    // TGraphErrors ou TGraph lê o arquivo diretamente
    // "dados_galaxia.txt" é o nome do arquivo, "%lg %lg" indica dois números decimais
    TGraph *graph = new TGraph("dados_raios_cosmicos.txt", "%lg %lg");
    
    // Estética do Gráfico (Padrão de publicação científica)
    graph->SetTitle("Perfil de Densidade de Raios Cosmicos (1D);Posicao z (Disco Galactico);Densidade N(z)");
    graph->SetMarkerStyle(21); // Quadrados
    graph->SetMarkerColor(kBlue);
    graph->SetLineColor(kBlue + 2);
    graph->SetLineWidth(2);
    
    // Desenha com linhas e pontos
    graph->Draw("ALP");
    
    // Salva uma imagem automaticamente para o seu relatório
    c1->SaveAs("grafico_raios_cosmicos.png");
}