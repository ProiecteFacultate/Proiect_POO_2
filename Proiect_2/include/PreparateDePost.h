#ifndef PREPARATEDEPOST_H
#define PREPARATEDEPOST_H
#include "Produs.h"


class PreparateDePost: virtual public Produs
{

protected:
    std::string esteDinSoia;  //TRUE or FALSE

private:
    std::string contineOua;
    std::string contineLapte;

    Produs *parentClass;

public:
    PreparateDePost();
    PreparateDePost(std::string, std::string, std::string, std::string, int, int, int, int, int);
    PreparateDePost(const PreparateDePost&);
    PreparateDePost& operator=(PreparateDePost&);
    ~PreparateDePost();

    friend std::istream& operator>>(std::istream&, PreparateDePost&);
    friend std::ostream& operator<<(std::ostream&, PreparateDePost&);

    void afiseazaProdus();

    void setParentClass();
    Produs* getParentClass();

    void afiseazaTipulProdusului();

    void esteProdusVegan() const;
};

#endif // PREPARATEDEPOST_H
