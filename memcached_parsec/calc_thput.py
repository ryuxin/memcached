input_file = 'example_output.txt'
thput = []
write_avg = []
read_avg = []

f = open(input_file, 'r')
lines = f.readlines()
f.close()

for l in lines:
    l = l.strip().split(",")[-1]
    x = l.split(" ")
    for i in range(len(x)):
        if x[i] == "thput":
            thput.append(int(x[i+1]))
        elif x[i] == "r_avg":
            read_avg.append(int(x[i+1]))
        elif x[i] == "w_avg":
            write_avg.append(int(x[i+1]))
print "thput: ",sum(thput), "w_avg: ", sum(write_avg)/len(write_avg), "r_avg: ", sum(read_avg)/len(read_avg)
