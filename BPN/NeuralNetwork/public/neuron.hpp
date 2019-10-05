#ifndef NEURALNETWORK_PUBLIC_NEURON_HPP
#define NEURALNETWORK_PUBLIC_NEURON_HPP

#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>

#include <NeuralNetwork/public/activationFunction.hpp>
#include <vector>

namespace NeuralNetwork_ns
{

	class Neuron
	{
	public:
		Neuron();
		Neuron(NeuralNetwork_ns::synapse_list_t m_Weights, NeuralNetwork_ns::bias_t m_Bias);


		NeuralNetwork_ns::output_t calculateOutput(NeuralNetwork_ns::output_list_t& input);

		// Get/Set Weights;
		NeuralNetwork_ns::synapse_list_t GetWeights();
		void SetWeights(NeuralNetwork_ns::synapse_list_t);

		NeuralNetwork_ns::weight_t GetWeight(NeuralNetwork_ns::neuron_id_t synapse);
		void SetWeight(NeuralNetwork_ns::neuron_id_t synapse, NeuralNetwork_ns::weight_t weight);

		// Get/Set Bias
		NeuralNetwork_ns::bias_t GetBias();
		void SetBias(NeuralNetwork_ns::bias_t bias);
	
	private:
		NeuralNetwork_ns::synapse_list_t m_Weights;
		NeuralNetwork_ns::bias_t m_Bias;

		NeuralNetwork_ns::ActivationFunction::IActivationFunction m_ActivationFunction;
	};

}

#endif // NEURALNETWORK_PUBLIC_NEURON_HPP
