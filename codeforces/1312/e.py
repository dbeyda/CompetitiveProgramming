def smallest_merge_seq(seq):
    seqs = [seq]
    for i in range(len(seq)):
        if i < len(seq) -1 and seq[i] == seq[i+1]:
            new_seq = seq.copy()
            new_seq[i+1] += 1
            del new_seq[i]
            print (new_seq)
            seqs.append(smallest_merge_seq(new_seq))
   
    return min(seqs, key=lambda x: len(x))

if __name__ == "__main__":
    
    seq = [4, 3, 2, 2, 3]
    print("min size: {}\n", len(smallest_merge_seq(seq)))
