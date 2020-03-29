SELECT continent as kontinent, sum(population) as anzahleute
FROM b7_a2_d
GROUP BY continent;