#ifndef _ROCK_HH_
#define _ROCK_HH_

class Rock {

  public:
    Rock(unsigned long engraving);
    void Blink();
    void Print();
    void Insert(unsigned long engraving);
    unsigned int Count();
    static void Prune(Rock* head);

  private:
    Rock(unsigned long engraving, Rock* next);
    Rock(unsigned long engraving, unsigned int multiplicity, Rock* next);
    static unsigned int Prune(unsigned long engraving_to_find, Rock* under_evaluation, Rock* previous);
    int NumberOfDigits();
    unsigned long engraving_ = 0U;
    unsigned int multiplicity_ = 1U;
    Rock* next_ = nullptr;

};

#endif