<ComposableMap
    projectionConfig={{
    rotate: [0, -5, 0],
    scale: 200
    }}>
        <Geographies geography={this.geoUrl}>
        {({ geographies }) => 
        geographies.map(
            geo => (<Geography
                key={geo.rsmKey}
                geography={geo}
                fill="#EAEAEC"
                stroke="#D6D6DA"
            />))}
        </Geographies>

        {logData.map(({ bad_requests, coordinate,good_requests, requests_number, index})=>(
            <Marker key ={index} coordinates={[coordinate.longitude, coordinate.latitude]}>
                <circle r={2} fill={requests_number <= 800 ? green : red } stroke="#fff" strokeWidth={0} />
            </Marker>
        ))}
</ComposableMap>