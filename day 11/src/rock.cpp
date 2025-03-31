#include "rock.hh"

#include <iostream>

Rock::Rock(unsigned long long engraving) :
  engraving_(engraving),
  multiplicity_(1UL),
  next_(nullptr) {
}

Rock::Rock(unsigned long long engraving, Rock* next) :
  engraving_(engraving),
  multiplicity_(1UL),
  next_(next) {
}

Rock::Rock(unsigned long long engraving, unsigned long multiplicity, Rock* next) :
  engraving_(engraving),
  multiplicity_(multiplicity),
  next_(next) {
}

Rock::Rock(const Rock& other) :
  engraving_(other.engraving_),
  multiplicity_(other.multiplicity_) {
    // deep copy the other Rock, starting from the given one
    if(other.next_) {
        this->next_ = new Rock(*other.next_);
    } else {
        this->next_ = nullptr;
    }
}

void Rock::Insert(unsigned long long engraving) {
    if(next_ == nullptr) {
        next_ = new Rock(engraving);
    } else {
        next_->Insert(engraving);
    }
}

unsigned long Rock::Count() {
    if(next_ == nullptr) {
        return multiplicity_;
    }
    return multiplicity_ + next_->Count();
}

void Rock::Print() {
    std::cout << engraving_ << ": ";
    std::cout << multiplicity_;
    if(next_ != nullptr) {
        std::cout << ", ";
        next_->Print();
    }
}

// The "Blink" function contains the rules for the puzzle that occur when you blink.
void Rock::Blink() {

    // Rule 1: if the engraving is 0, it becomes 1
    if(engraving_ == 0ULL) {
        engraving_ = 1ULL;
        if(next_)
            next_->Blink();
    } 
    // Rule 2: If there are an even number of digits, replace the stone with 2 stones, splitting the digits left and right evenly.
    else if(NumberOfDigits() % 2 == 0) {

        int digits = NumberOfDigits();
        unsigned long long divisor = 1;
        unsigned long long temp_engraving = 0ULL;
        for(int i = 0; i < digits/2; i++) {
            temp_engraving += ((engraving_/divisor) % 10ULL) * divisor;
            divisor *= 10ULL;
        }
        unsigned long long left = engraving_/divisor;
        unsigned long long right = temp_engraving;

        engraving_ = left;
        Rock* temp = next_;

        next_ = new Rock(right, multiplicity_, temp);

        if(temp)
            temp->Blink();

    } 
    // Rule 3: multiply the old engraving number by 2024
    else {
        engraving_ *= 2024U;
        if(next_)
            next_->Blink();
    }

}

// This is the top-level outer wrapper for pruning the duplicates out of the Rock chain
void Rock::Prune(Rock* head) {

    Rock* current = head;
    while(current != nullptr && current->next_ != nullptr) {

        current->multiplicity_ += Prune(current->engraving_, current->next_, current);
        current = current->next_;

    }

}

// This method does the pruning
unsigned long Rock::Prune(unsigned long long engraving_to_find, Rock* under_evaluation, Rock* previous) {

    // match: prune the current Rock, return its multiplicity plus the Prune value of the rest of the chain
    if(under_evaluation->engraving_ == engraving_to_find) {

        // save the important features
        previous->next_ = under_evaluation->next_;
        unsigned long saved_multiplicity = under_evaluation->multiplicity_;

        // delete the Rock under evaluation, and point to the next in line instead
        delete under_evaluation;

        // now, recurse if necessary, or just return
        if(previous != nullptr && previous->next_ != nullptr) {
            return saved_multiplicity + Prune(engraving_to_find, previous->next_, previous);
        }

        return saved_multiplicity;

    }

    // otherwise, just do the prune step
    if(under_evaluation->next_ != nullptr) {
        return Prune(engraving_to_find, under_evaluation->next_, under_evaluation);
    }
    return 0U;

}


int Rock::NumberOfDigits() {

    int digits = 0;
    unsigned long long number = engraving_;
    while (number) {
        number /= 10ULL;
        digits++;
    }
    return digits;

}
    
    