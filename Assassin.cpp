#include <iostream>
#include <string>


class Personnage {
protected:
    std::string nom;
    int niveau;

public:
    
    Personnage() : nom(""), niveau(1) {}

    
    Personnage(const std::string& n, int lvl) : nom(n), niveau(lvl) {}

    
    Personnage(const std::string& n) : nom(n), niveau(1) {}

    
    Personnage(int lvl) : nom("Anonyme"), niveau(lvl) {}

    
    virtual ~Personnage() {}

    
    void afficherDetails() const {
        std::cout << "Nom: " << nom << ", Niveau: " << niveau << std::endl;
    }

    
    virtual void effectuerMission() const = 0;
};


class Assassin : public Personnage {
private:
    std::string arme;

public:
    
    Assassin() : arme("Lame secrete") {}

    
    Assassin(const std::string& n, int lvl, const std::string& a) : Personnage(n, lvl), arme(a) {}

    
    Assassin(const std::string& n, int lvl) : Personnage(n, lvl), arme("Lame secrète") {}

    
    Assassin(const std::string& n, const std::string& a) : Personnage(n), arme(a) {}

    
    void utiliserLameSecrete() const {
        std::cout << "Utilisation de la lame secrete!" << std::endl;
    }

    
    void effectuerMission() const override {
        std::cout << "Assassin " << nom << " effectue une mission d'assassinat." << std::endl;
    }
};


class Mission {
private:
    std::string objectif;

public:
    
    Mission() : objectif("Mission secrete") {}

    
    Mission(const std::string& obj) : objectif(obj) {}

    
    Mission(int niveau) : objectif("Mission de niveau " + std::to_string(niveau)) {}

    
    Mission(int niveau, const std::string& obj) : objectif("Mission de niveau " + std::to_string(niveau) + ": " + obj) {}

    
    void afficherObjectif() const {
        std::cout << "Objectif de la mission: " << objectif << std::endl;
    }
};

int main() {
    
    Assassin ezio("Ezio", 30, "Lame Secrete");
    ezio.afficherDetails();
    ezio.effectuerMission();
    ezio.utiliserLameSecrete();

    Mission missionSecrete("Retrouver un artefact ancien");
    missionSecrete.afficherObjectif();

    return 0;
}
