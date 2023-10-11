function solve(  )
    raio = 6000 * 1000;
    area = 4 * π * raio * raio;

    # Find the percentage of Area which the ocean hits.
    portion = ( 1.00 - 0.79 );
    area    = area * portion;

    num_of_people = 8.1e9;

    return area / num_of_people;
end

function main()
    result = solve();
    result = round(result);

    println("A área distribuída será de $result m² para cada pessoa.");
end