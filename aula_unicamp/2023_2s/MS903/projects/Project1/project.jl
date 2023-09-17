global data;

file_path = "data.txt";
data      = Vector{Vector{Float64}}();

function main(filepath)
    file = open(filepath, "r");
    for line in eachline(file)
        row = parse.(Float64, split(line));
        push!(data, row);
    end

    close(file);
end

main(file_path)

