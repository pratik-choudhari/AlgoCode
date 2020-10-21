import React from 'react';
import View from './components/View';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      currentTime: 0,
      interval: null,
      isRunning: false
    }
  }

  onStart = () => {
    this.setState({
      interval: setInterval(() => {
        this.setState({ currentTime: this.state.currentTime + 1 });
      }, 1),
      isRunning: true
    });
  }

  onStop = () => {
    clearInterval(this.state.interval);
    this.setState({ isRunning: false });
  }

  onReset = () => {
    this.setState({ currentTime: 0 });
    this.onStop();
  }

  render() {
    return <View isRunning={this.state.isRunning} currentTime={this.state.currentTime} onStart={this.onStart} onStop={this.onStop} onReset={this.onReset} />
  }
}


export default App;
