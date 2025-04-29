from cs50 import get_string


def main():
    # prompt the user for a sentence
    sentence = get_string("Sentence : ")
    # check the number of leters,words,sentences
    l = letter(sentence) * 100 / word(sentence)
    s = sentences(sentence) * 100 / word(sentence)
    # put it in coleman liau index
    # 0.0588(l) - 0.296(s)-15.8
    # l is average no. of letters per 100 words. s is average no. of sentences per 100 words
    x = round(0.0588 * (l) - 0.296 * (s)-15.8)
    if x < 0:
        print("Before Grade 1")
    elif x > 16:
        print("Grade 16+")
    else:
        print(f"Grade {x}")
    # print whether the sentence is before grade 1,grade 1,''''''''''''''grade 16 or grade 16+


def letter(text):
    count = 0
    for i in text:
        if i.isalpha():
            count += 1
    return count


def word(text):
    return text.count(' ') + 1


def sentences(text):
    return text.count('?') + text.count('.') + text.count('!')


main()
