void graficos()
{
    TCanvas *c = new TCanvas("c", "Perfis de densidade", 1000, 800);
    c->Divide(2,2);

    c->cd(1);
    TGraph *gN0 = new TGraph("dados_raios_cosmicos.txt", "%lg %lg");
    gN0->SetTitle("Perfil de densidade N(0);z;N");
    gN0->SetMarkerStyle(20);
    gN0->Draw("ALP");

    c->cd(2);
    TGraph *gN1 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %lg");
    gN1->SetTitle("Perfil de densidade N(1);z;N");
    gN1->SetMarkerStyle(20);
    gN1->Draw("ALP");

    c->cd(3);
    TGraph *gN2 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %*lg %lg");
    gN2->SetTitle("Perfil de densidade N(2);z;N");
    gN2->SetMarkerStyle(20);
    gN2->Draw("ALP");

    c->cd(4);
    TGraph *gN3 = new TGraph("dados_raios_cosmicos.txt", "%lg %*lg %*lg %*lg %lg");
    gN3->SetTitle("Perfil de densidade N(3);z;N");
    gN3->SetMarkerStyle(20);
    gN3->Draw("ALP");

    c->Update();
}