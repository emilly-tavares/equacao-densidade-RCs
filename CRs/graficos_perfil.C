void graficos_perfil()
{
    TCanvas *c = new TCanvas("c", "Perfis de densidade", 1200, 800);
    c->Divide(3,2);

    int cor = kOrange+1;

    // N(3)
    c->cd(1);
    TGraph *gN3 = new TGraph("dados_raios_cosmicos.txt", "%lg %lg");
    gN3->SetTitle("Perfil de densidade N(3);z;N");
    gN3->SetMarkerStyle(20);
    gN3->SetLineColor(cor);
    gN3->SetMarkerColor(cor);
    gN3->SetMinimum(0);
    gN3->SetMaximum(1);
    gN3->Draw("ALP");

    // N(5)
    c->cd(2);
    TGraph *gN5 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %lg");
    gN5->SetTitle("Perfil de densidade N(5);z;N");
    gN5->SetMarkerStyle(20);
    gN5->SetLineColor(cor);
    gN5->SetMarkerColor(cor);
    gN5->SetMinimum(0);
    gN5->SetMaximum(1);
    gN5->Draw("ALP");

    // N(10)
    c->cd(3);
    TGraph *gN10 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %*lg %lg");
    gN10->SetTitle("Perfil de densidade N(10);z;N");
    gN10->SetMarkerStyle(20);
    gN10->SetLineColor(cor);
    gN10->SetMarkerColor(cor);
    gN10->SetMinimum(0);
    gN10->SetMaximum(1);
    gN10->Draw("ALP");

    // N(15)
    c->cd(4);
    TGraph *gN15 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %*lg %*lg %lg");
    gN15->SetTitle("Perfil de densidade N(15);z;N");
    gN15->SetMarkerStyle(20);
    gN15->SetLineColor(cor);
    gN15->SetMarkerColor(cor);
    gN15->SetMinimum(0);
    gN15->SetMaximum(1);
    gN15->Draw("ALP");

    // N(20)
    c->cd(5);
    TGraph *gN20 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %*lg %*lg %*lg %lg");
    gN20->SetTitle("Perfil de densidade N(20);z;N");
    gN20->SetMarkerStyle(20);
    gN20->SetLineColor(cor);
    gN20->SetMarkerColor(cor);
    gN20->SetMinimum(0);
    gN20->SetMaximum(1);
    gN20->Draw("ALP");

    // N(100)
    c->cd(6);
    TGraph *gN100 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %*lg %*lg %*lg %*lg %lg");
    gN100->SetTitle("Perfil de densidade N(100);z;N");
    gN100->SetMarkerStyle(20);
    gN100->SetLineColor(cor);
    gN100->SetMarkerColor(cor);
    gN100->SetMinimum(0);
    gN100->SetMaximum(1);
    gN100->Draw("ALP");

    c->Update();
}