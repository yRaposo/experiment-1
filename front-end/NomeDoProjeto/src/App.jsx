import { useState, useEffect } from 'react';
import axios from 'axios';

function App() {
  const [clicks, setClicks] = useState(0);

  useEffect(() => {
    // Obtenha a variável Click do servidor quando o componente for montado
    axios.get('http://192.168.1.13:8081/clicks')
      .then(response => {
        setClicks(response.data.clicks);
      });
  }, []);

  const handleClick = () => {
    // Envie uma solicitação ao servidor quando o botão for clicado
    axios.post('http://seu_servidor_nodejs:8081/clicks', { clicks: clicks + 1 })
      .then(() => {
        setClicks(clicks + 1);
      });
  };

  return (
    <div>
      <p>Clicks: {clicks}</p>
      <button onClick={handleClick}>Click me</button>
    </div>
  );
}

export default App;
